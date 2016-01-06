--Question 1 :

BEGIN;
	INSERT INTO Films VALUES (8, 'J.J.Abrams', 'La suite du réveil', 'premier ordre');
	INSERT INTO Statut VALUES ('Luke Skywalker',8,'Jedi');
	INSERT INTO Statut VALUES ('Leia Organa',8,'Jedi');
	INSERT INTO Statut VALUES ('Chewbacca',8,'Pilote');
COMMIT;


--Question 2 :

--user1
BEGIN;
	UPDATE Statut set nomp='Han Solo' where nomp='Luke Skywalker' and num=8;
--user2
	SELECT nomp from statut where num=8;
--user1
ROLLBACK;
SELECT nomp from statut where num=8;


--Question 3 :

--user1
BEGIN;
--user2
BEGIN;
--user1
	UPDATE Statut set nomp='Han Solo' where nomp='Luke Skywalker' and num=8;
--user2
	UPDATE Statut set nomp='Boba Fett' where nomp='Luke Skywalker' and num=8;
--user1
COMMIT;
--user2
COMMIT;

SELECT nomp from statut where num=8;


--Question 4:

--user1
BEGIN;
--user2
SELECT * from Statut where num=8;
--user1
	UPDATE Statut set nomp='Han Solo' where nomp='Luke Skywalker' and num=8;
COMMIT;
--user2
SELECT * from Statut where num=8;


--Question 5 : 

--user1
BEGIN;
--user2
BEGIN;
--user1
	UPDATE Statut set nomp='Han Solo' where nomp='Luke Skywalker' and num=8;
--user2
	UPDATE Statut set nomp='Boba Fett' where nomp='Leia Organa' and num=8;
--user1
	UPDATE Statut set nomp='Boba Fett' where nomp='Luke Skywalker' and num=8;
--user2
	UPDATE Statut set nomp='Han Solo' where nomp='Leia Organa' and num=8;
--user1
COMMIT;
--user2
COMMIT;


