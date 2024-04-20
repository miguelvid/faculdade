INSERT INTO Editora (cdeditora, nmeditora, endereco, contato)
VALUES
    (1, 'Editora A', 'Rua A da Editora, 123', 'contato@editoraa.com'),
    (2, 'Editora B', 'Rua B da Editora, 345', 'contato@editorab.com'),
    (3, 'Editora C', 'Rua C da Editora, 567', 'contato@editorac.com'),
    (4, 'Editora D', 'Rua D da Editora, 789', 'contato@editorad.com'),
    (5, 'Editora E', 'Rua E da Editora, 910', 'contato@editorae.com');

INSERT INTO Autor (cdautor, nmautor, nacionalidade)
VALUES
    (1, 'João Silva', 'Brasileira'),
    (2, 'Maria Oliveira', 'Portuguesa'),
    (3, 'Pedro Santos', 'Brasileira'),
    (4, 'Ana Sousa', 'Espanhola'),
    (5, 'Miguel Costa', 'Brasileira');

INSERT INTO Funcionario (cdfuncionario, nmfuncionario, cpf, funcao, salario, telefone, endereco, dtnascimento)
VALUES
    (1, 'Carlos Silva', '12345678901', 'Editor', 5000.00, '987654321', 'Rua do Funcionário, 1', '1999-01-10'),
    (2, 'Ana Souza', '98765432109', 'Assistente Editorial', 3500.00, '123456789', 'Avenida do Trabalhador, 2', '1992-02-15'),
    (3, 'Paulo Oliveira', '23456789012', 'Revisor', 4500.00, '345678901', 'Rua do Revisor, 3', '1999-03-20'),
    (4, 'Marta Santos', '34567890123', 'Gerente de Publicações', 6000.00, '456789012', 'Avenida do Gerente, 4', '1999-04-25'),
    (5, 'Fernanda Costa', '45678901234', 'Designer Gráfico', 4000.00, '567890123', 'Rua do Designer, 5', '1999-05-30');

INSERT INTO Usuario (cdusuario, nmusuario, cpf, telefone, endereco)
VALUES
    (1, 'José Oliveira', '56789012345', '678901234', 'Rua do Leitor, 6'),
    (2, 'Mariana Santos', '67890123456', '789012345', 'Avenida do Usuário, 7'),
    (3, 'Luiz Souza', '78901234567', '890123456', 'Rua do Leitor, 8'),
    (4, 'Amanda Costa', '89012345678', '901234567', 'Avenida do Leitor, 9'),
    (5, 'Gabriel Silva', '90123456789', '012345678', 'Rua do Leitor, 10');

INSERT INTO Livro (nrlivro, genero, titulo, ano_publicacao, edicao, fkusuario, fkeditora, fkfuncionario)
VALUES
    (1, 'Romance', 'Aventuras de João', '2020-01-15', 1, 1, 1, 1),
    (2, 'Ficção Científica', 'Viagem a Marte', '2018-06-20', 2, 2, 2, 2),
    (3, 'Drama', 'O Jardim Secreto', '2015-11-30', 1, 3, 3, 3),
    (4, 'Suspense', 'O Silêncio dos Inocentes', '1998-03-10', 3, 4, 4, 4),
    (5, 'Aventura', 'As Aventuras de Alice no País das Maravilhas', '1865-07-04', 1, 5, 5, 5);

INSERT INTO Escreve (fkautor, nrlivro)
VALUES
    (1, 1), -- João Silva escreveu "Aventuras de João"
    (2, 2), -- Maria Oliveira escreveu "Viagem a Marte"
    (3, 3), -- Pedro Santos escreveu "O Jardim Secreto"
    (4, 4), -- Ana Sousa escreveu "O Silêncio dos Inocentes"
    (5, 5); -- Miguel Costa escreveu "As Aventuras de Alice no País das Maravilhas"

