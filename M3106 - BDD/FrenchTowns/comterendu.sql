--Exercice 1
--1)
SELECT relname, relpages, reltuples from pg_class order by relname;
--Pour trouver les indexes : \d nomtable
--pg_class : liste les tables et tout ce qui contient des colonnes ou ressemble à une table.
--relname : nom de la table, vue...
--relpages : taille du fichier sur le disque
--reltuples : nombre de lignes de la table
--departments                             |        1 |       100
--departments_capital_key                 |        2 |       100
--departments_id_key                      |        2 |       100
--departments_id_seq                      |        1 |         1

--2)
--Analyze : mettre à jour données statistiques

--Exercice 2
--1)
EXPLAIN SELECT * FROM towns;
--On peut voir les couts minimaux et maximaux (0.00, 617.84)
--Recherche séquentielle

--2)

--Exercice 3
--1)
SELECT * FROM towns WHERE name = 'Grenoble';
--  id   | code | article |   name   | department 
---------+------+---------+----------+------------
-- 14859 | 185  |         | Grenoble | 38

SELECT t.code, t.name
FROM towns t, departments d
WHERE t.department = d.code
AND d.name = 'Isère';

--------------------------------------------------------------------------------
--TP Optimisation, 2é partie

--Exercice 2
EXPLAIN SELECT * FROM towns;
--Seq Scan on towns  (cost=0.00..617.84 rows=36684 width=54)

explain select code_town, article, name_town, code_departement from all_in_one;
--Seq Scan on all_in_one  (cost=0.00..794.84 rows=36684 width=19)

explain select d.name, department, region from towns t, departments d where t.department = d.code;
Hash Join  (cost=3.25..1125.50 rows=36684 width=16)
Hash Cond: ((t.department)::text = (d.code)::text)
->  Seq Scan on towns t  (cost=0.00..617.84 rows=36684 width=3)
->  Hash  (cost=2.00..2.00 rows=100 width=16)
->  Seq Scan on departments d  (cost=0.00..2.00 rows=100 width=16)
(5 rows)

explain SELECT DISTINCT code_region, capital_region,
capital_departement, name_departement
FROM all_in_one;
HashAggregate  (cost=1161.68..1198.37 rows=3669 width=24)
Group Key: code_region, capital_region, capital_departement, name_departement
->  Seq Scan on all_in_one  (cost=0.00..794.84 rows=36684 width=24)
(3 rows)


