INSERT INTO Local (DSLOCAL) VALUES
    ('Local 1'),
    ('Local 2'),
    ('Local 3'),
    ('Local 4'),
    ('Local 5');

INSERT INTO Empresa (NMEMPRESA, DTFUNDACAO, FKLOCAL) VALUES
    ('Empresa 1', '2023-01-01', 1),
    ('Empresa 2', '2023-01-01', 2),
    ('Empresa 3', '2023-01-01', 3),
    ('Empresa 4', '2023-01-01', 4),
    ('Empresa 5', '2023-01-01', 5);

INSERT INTO Projeto (FKEMPRESA, CDPROJETO, DSPROJETO) VALUES
    (1, 1, 'Projeto 1'),
    (1, 2, 'Projeto 2'),
    (2, 1, 'Projeto 3'),
    (3, 1, 'Projeto 4'),
    (4, 1, 'Projeto 5');

INSERT INTO Categoria (DSCATEGORIA) VALUES
    ('Categoria 1'),
    ('Categoria 2'),
    ('Categoria 3'),
    ('Categoria 4'),
    ('Categoria 5');

INSERT INTO Empresa_Categoria (FKEMPRESA, FKCATEGORIA) VALUES
    (1, 1),
    (1, 2),
    (2, 3),
    (3, 4),
    (4, 5);
    
INSERT INTO Integrante (NMINTEGRANTE) VALUES
    ('Integrante 1'),
    ('Integrante 2'),
    ('Integrante 3'),
    ('Integrante 4'),
    ('Integrante 5');

INSERT INTO Projeto_Integrante (FKEMPRESA, CDPROJETO, FKINTEGRANTE, VLCOBRADO) VALUES
    (1, 1, 1, 100.50),
    (1, 1, 2, 120.75),
    (1, 2, 3, 90.25),
    (2, 1, 4, 110.00),
    (3, 1, 5, 95.50);