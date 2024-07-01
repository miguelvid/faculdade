from vertice import Vertice
class Grafo:
    def __init__(self) -> None:
        self.vertices = []
        
        
    def get_vertice(self, valor: int) -> Vertice:
        for vertice in self.vertices:
            if vertice.valor == valor:
                return vertice
        return None
    
    def get_vertices(self) -> list:
        
        return [vertice for vertice in self.vertices]
    
    def get_vizinhos_vertice(self) -> list:
        pass
    
    def get_arestas(self) -> list:
        arestas = []
        for vertice in self.vertices:
            aresta_vertice = vertice.get_vizinhos()
            if aresta_vertice:
                for vizinho, peso in aresta_vertice:
                    arestas.append((vertice.valor, vizinho, peso))
        if arestas:
            return arestas
        else:
            return None

    def get_grau_vertices(self) -> list:
        vertices_grau = {}
        if self.vertices:
            for vertice in self.vertices:
                vertices_grau[vertice.valor] = vertice.get_grau()
        
            return vertices_grau
        else:
            return None
    
    def get_vertices_isolados(self) -> list:
        pass

    def get_min_max_grau(self) -> tuple:
        if self.vertices:
            graus = [vertice.get_grau() for vertice in self.vertices]
            return (max(graus), min(graus))
        else:
            return None

    def add_vertice(self, valor: int):
        novo_vertice = Vertice(valor)
        self.vertices.append(novo_vertice)

    def add_aresta(self, origem: int, destino: int, peso: int) -> bool:
        
        vertice_origem = self.get_vertice(origem)
        vertice_destino = self.get_vertice(destino)

        if vertice_origem and vertice_destino:
            if vertice_origem != vertice_destino:
                vertice_origem.add_vizinho(vertice_destino, peso)
                vertice_destino.add_vizinho(vertice_origem, peso)
            else:
                vertice_origem.add_vizinho(vertice_destino, peso)
            return True
            
        else:
            return False

    def lista_adjacencia(self) -> dict:
        lista_adjacencia = {}
        
        for vertice in self.vertices:
            if vertice.get_vizinhos():
                lista_adjacencia[vertice.valor] = [(vertice[0].valor, vertice[1]) for vertice in vertice.get_vizinhos()]
            else:
                lista_adjacencia[vertice.valor] = []

        return lista_adjacencia
    
    def matriz_adjacencia(self) -> list:
        lista_adjacencia = self.lista_adjacencia()
        tamanho = len(self.vertices)
        
        matriz = [[0 for _ in range(tamanho)] for _ in range(tamanho)]

        if lista_adjacencia:
            for vertice, vizinhos in lista_adjacencia.items():
                chave = vertice - 1  
                for vizinho, _ in vizinhos:  
                    valor = vizinho - 1  
                    matriz[chave][valor] += 1  

        return matriz
        
    def reiniciar_grafo(self) -> int:
        self.vertices = []
        return 1

    def are_vizinhos(self, v1: int, v2: int) -> int:
        vertice1 = self.get_vertice(v1)
        vertice2 = self.get_vertice(v2)

        if not (vertice1 and vertice2):
            return -1
        for vizinho, _ in vertice1.vizinhos:
            if vizinho.valor == vertice2.valor:
                return 1
        return 0
        

    def is_multigrafo(self) -> int:
        lista_adjacencia = self.lista_adjacencia()
        incidencia_vizinhos = {}
        if not lista_adjacencia: 
            return -1
        elif all(not v for v in lista_adjacencia.values()):
            return -2
        for vertice, vizinhos in lista_adjacencia.items():
            if vertice not in incidencia_vizinhos:
                incidencia_vizinhos[vertice] = set()
            if vizinhos:
                if vertice in vizinhos[0]:
                    return 1
            for vizinho, _ in vizinhos:
                if vizinho in incidencia_vizinhos[vertice] :
                    return 1  
                else:
                    incidencia_vizinhos[vertice].add(vizinho)
        return 0
        

    def existe_caminho_entre_vertices(self) -> bool:
        pass

    def is_ciclo(self) -> bool:
        pass

    def is_conexo(self) -> bool:
        pass