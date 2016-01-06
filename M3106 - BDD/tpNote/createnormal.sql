create table ere(
		epoque TEXT primary key,
		début SMALLINT NOT NULL,
		fin SMALLINT NOT NULL
);

create table personnage(
		nomP TEXT primary key,
		genre TEXT,
		espece TEXT NOT NULL
);

create table films(
		num smallint primary KEY,
		real text NOT NULL,
		resume text,
		epoque text REFERENCES ere(epoque)
);

create table statut(
		nomP TEXT REFERENCES personnage(nomP),
		num SMALLINT REFERENCES films(num),
		statut TEXT,
		PRIMARY KEY (NomP, Num)
);

INSERT INTO ere VALUES('ancienne république', -25000, -19);
INSERT INTO ere VALUES('empire', -19, 4);
INSERT INTO ere VALUES('premier ordre', 4, 40);

INSERT INTO films VALUES(1, 'George Lucas', 'Anakin découvre la force','ancienne république');
INSERT INTO films VALUES(2, 'George Lucas', 'Un si beau couple','ancienne république');
INSERT INTO films VALUES(3, 'George Lucas', 'Coup de chaud pour le seigneur Vador','ancienne république');
INSERT INTO films VALUES(4, 'George Lucas', 'Ça va péter','empire');
INSERT INTO films VALUES(5, 'George Lucas', 'Je suis ton père','empire');
INSERT INTO films VALUES(6, 'George Lucas', 'Ça va encore péter','empire');
INSERT INTO films VALUES(7, 'J. J. Abrams', 'Le premier ordre à la traine','premier ordre');

INSERT INTO personnage VALUES('Obi-Wan Kenobi', 'masculin', 'humain');
INSERT INTO personnage VALUES('Jabba', 'Hermaphrodite', 'hutt');
INSERT INTO personnage VALUES ('Han Solo', 'masculin', 'humain');
INSERT INTO personnage VALUES ('Chewbacca', 'masculin', 'wookie');
INSERT INTO personnage VALUES ('Luke Skywalker', 'masculin', 'humain');
INSERT INTO personnage VALUES ('Leia Organa', 'féminin', 'humain');
INSERT INTO personnage VALUES ('Yoda', 'masculin', 'Inconnu');
INSERT INTO personnage VALUES ('Anakin Skywalker', 'masculin', 'humain');
INSERT INTO personnage VALUES ('Dark Vador', 'masculin', 'humain');
INSERT INTO personnage VALUES ('Dark Maul', 'masculin', 'Zabrak');
INSERT INTO personnage VALUES ('Palpatine', 'masculin', 'humain');
INSERT INTO personnage VALUES ('Padmé Amidala', 'féminin', 'humain');
INSERT INTO personnage VALUES ('R2-D2', 'aucun', 'droide');
INSERT INTO personnage VALUES ('C-3PO', 'aucun', 'droide');
INSERT INTO personnage VALUES ('Jango Fett', 'masculin', 'humain');
INSERT INTO personnage VALUES ('Boba Fett', 'masculin', 'humain');

INSERT into statut VALUES('Obi-Wan Kenobi', 2, 'Jedi');
INSERT into statut VALUES('Obi-Wan Kenobi', 3, 'Jedi');
INSERT into statut VALUES('Obi-Wan Kenobi', 4, 'Jedi');
INSERT into statut VALUES('Jabba', 5, 'Gangster');
INSERT into statut VALUES('Han Solo', 5, 'Contrebandier');
INSERT into statut VALUES('Han Solo', 6, 'Contrebandier');
INSERT into statut VALUES('Chewbacca', 4, 'Pilote');
INSERT into statut VALUES('Chewbacca', 5, 'Pilote');
INSERT into statut VALUES('Chewbacca', 6, 'Pilote');
INSERT into statut VALUES('Chewbacca', 7, 'Pilote');
INSERT into statut VALUES('Luke Skywalker', 4, 'Jedi');
INSERT into statut VALUES('Luke Skywalker', 5, 'Jedi');
INSERT into statut VALUES('Luke Skywalker', 6, 'Jedi');
INSERT into statut VALUES('Leia Organa', 4, 'Jedi');
INSERT into statut VALUES('Leia Organa', 5, 'Jedi');
INSERT into statut VALUES('Leia Organa', 6, 'Jedi');
INSERT into statut VALUES('Yoda', 1, 'Jedi');
INSERT into statut VALUES('Yoda', 2, 'Jedi');
INSERT into statut VALUES('Yoda', 3, 'Jedi');
INSERT into statut VALUES('Yoda', 5, 'Jedi');
INSERT into statut VALUES('Yoda', 6, 'Jedi');
INSERT into statut VALUES('Anakin Skywalker', 1, 'Jedi');
INSERT into statut VALUES('Anakin Skywalker', 2, 'Jedi');
INSERT into statut VALUES('Anakin Skywalker', 3, 'Jedi');
INSERT into statut VALUES('Dark Vador', 4, 'Sith');
INSERT into statut VALUES('Dark Vador', 5, 'Sith');
INSERT into statut VALUES('Dark Vador', 6, 'Sith');
INSERT into statut VALUES('Dark Maul', 1, 'Sith');
INSERT into statut VALUES('Palpatine', 1, 'Sith');
INSERT into statut VALUES('Palpatine', 2, 'Sith');
INSERT into statut VALUES('Palpatine', 3, 'Sith');
INSERT into statut VALUES('Palpatine', 5, 'Sith');
INSERT into statut VALUES('Palpatine', 6, 'Sith');
INSERT into statut VALUES('Padmé Amidala', 2, 'Politicien');
INSERT into statut VALUES('Padmé Amidala', 3, 'Politicien');
INSERT into statut VALUES('R2-D2', 1, 'Réparateur');
INSERT into statut VALUES('R2-D2', 2, 'Réparateur');
INSERT into statut VALUES('R2-D2', 3, 'Réparateur');
INSERT into statut VALUES('R2-D2', 4, 'Réparateur');
INSERT into statut VALUES('R2-D2', 5, 'Réparateur');
INSERT into statut VALUES('R2-D2', 6, 'Réparateur');
INSERT into statut VALUES('C-3PO', 1, 'Traducteur');
INSERT into statut VALUES('C-3PO', 2, 'Traducteur');
INSERT into statut VALUES('C-3PO', 3, 'Traducteur');
INSERT into statut VALUES('C-3PO', 4, 'Traducteur');
INSERT into statut VALUES('C-3PO', 5, 'Traducteur');
INSERT into statut VALUES('C-3PO', 6, 'Traducteur');
INSERT into statut VALUES('Jango Fett', 2, 'Chasseur de primes');
INSERT into statut VALUES('Boba Fett', 5, 'Chasseur de primes');
INSERT into statut VALUES('Boba Fett', 6, 'Chasseur de primes');
