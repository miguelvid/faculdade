instruction_set = {
    "MOV": "0001",
    "ADD": "0011",
    "SUB": "0100",
    "DIV": "0101",
    "MUL": "0110",
    "DEC": "0111",
    "INC": "1000",
    "JMP": "1001",
    "CMP": "1010",
    "JA": "1011",
    "JB": "1100",
    'R0': '000',
    'R1': '001',
    'R2': '010',
    'R3': '011',
    'R4': '100',
    'R5': '101',
    'R6': '110',
    'R7': '111',
}

def read_txt(file_path):
    with open(file_path, 'r') as file:
        code = file.readlines()

    cleaned_code = []
    for line in code:
        if ',' in line:
            line = line.replace(',', '')
        cleaned_code.append(line.strip())

    return [line for line in cleaned_code if line]

def assembly_to_binary(assembly_code):
    binary = []
    try:
        for line in assembly_code:
            parts = line.split()
            line = ''
            for part in parts:
                if part in instruction_set:
                    line = line + f"{instruction_set[part]} "
                elif int(part):
                    line = line + f"{bin(int(part))}"

            binary.append(line)

        return binary
            
    except Exception as e:
        print(e)

def calculate_register(registers, line, index):
    is_jump = False
    did_jump = False
    jmp_index = None
    instruction = line[0]
    dest = line[1]
    src1 = line[2] if len(line) > 2 else None
    src2 = line[3] if len(line) > 3 else None


    if src1 is not None:
        if src1 in registers:
            src1_value = registers[src1]
        else:
            src1_value = int(src1)
            
    if src2 is not None:
        if src2 in registers:
            src2_value = registers[src2]
        else:
            src2_value = int(src2)

    if instruction == "MOV":
        registers[dest] = registers.get(src1, int(src1))

    elif instruction == "INC":
        registers[dest] += 1
    elif instruction == "DEC":
        registers[dest] -= 1
    elif instruction == "ADD":
        registers[dest] = src1_value + int(src2_value) if src2 else int(src1_value) + registers[dest]
    elif instruction == "SUB":
        registers[dest] = src1_value - int(src2_value) if src2 else int(src1_value) - registers[dest]
    elif instruction == "DIV":
        registers[dest] = src1_value // int(src2_value) if src2 else registers[dest] // int(src1_value)
    elif instruction == "MUL":
        registers[dest] = src1_value * int(src2_value) if src2 else int(src1_value) * registers[dest]


    elif instruction in ["JMP","CMP", "JA","JB"]:
        is_jump = True
        did_jump = False

        if instruction == "JMP":
            jmp_index = index
            index = int(dest) - 1
            did_jump = True

        elif instruction == "CMP":
            if registers[dest] == src1_value:
                did_jump = True
                index += 1
        elif instruction == "JA":
            if registers[dest] > src1_value:
                did_jump = True
                index += 1
        elif instruction == "JB":
            if registers[dest] < src1_value:
                did_jump = True
                index += 1

    return registers, is_jump, did_jump, index, jmp_index

def execution_queue(assembly_code):
    counter = 0
    i = 0
    queue = []
    registers = {}

    try:

        while i < len(assembly_code):
            line = assembly_code[i].split()
            instruction = line [0]
            
            registers, is_jump, did_jump, i, jmp_index = calculate_register(registers, line, i)

            if is_jump:
                if did_jump:
                    if instruction == "JMP":
                        queue.append(jmp_index+1)
                        continue
                    else:
                        queue.append(i+1) 
                        i += 1
                else:
                    i += 1
            else:
                queue.append(i+1)
                i += 1

    
    except Exception as e:
        print(e)


    return {
        "queue": queue,
        "registers": registers
    }

txt = read_txt('a.txt')
binary = assembly_to_binary(txt)
run = execution_queue(txt)
print("ordem de execução (por linha): ", run['queue'])
print("registradores: ", run['registers'])