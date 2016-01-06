-- TP Noté M3106C Star Wars


BEGIN;

-- Schéma de la base de données

CREATE TABLE PERSONNAGES (
		NomP TEXT NOT NULL,
		Genre TEXT,
		Espèce TEXT NOT NULL,
		Epoque TEXT,
		Début SMALLINT NOT NULL,
		Fin SMALLINT NOT NULL,
		Statut TEXT,
		Num SMALLINT NOT NULL,
		Réal TEXT NOT NULL,
		Résumé TEXT,
		PRIMARY KEY (NomP, Num)
);

	-- Insertions
	INSERT INTO PERSONNAGES VALUES ('Obi-Wan Kenobi', 'masculin', 'humain', 'empire', -19, 4, 'Jedi', 4, 'George Lucas', 'Ça va péter');
	INSERT INTO PERSONNAGES VALUES ('Jabba', 'Hermaphrodite', 'hutt', 'empire', -19, 4, 'Gangster', 5, 'George Lucas', 'Je suis ton père');
	INSERT INTO PERSONNAGES VALUES ('Han Solo', 'masculin', 'humain', 'empire', -19, 4, 'Contrebandier', 4, 'George Lucas', 'Ça va péter');
	INSERT INTO PERSONNAGES VALUES ('Han Solo', 'masculin', 'humain', 'empire', -19, 4, 'Contrebandier', 5, 'George Lucas', 'Je suis ton père');
	INSERT INTO PERSONNAGES VALUES ('Han Solo', 'masculin', 'humain', 'empire', -19, 4, 'Contrebandier', 6, 'George Lucas', 'Ça va encore péter');
	INSERT INTO PERSONNAGES VALUES ('Han Solo', 'masculin', 'humain', 'premier ordre', 4, 40, 'Heros', 7, 'J. J. Abrams', 'Le premier ordre à la traine');
	INSERT INTO PERSONNAGES VALUES ('Chawbacca', 'masculin', 'wookie', 'empire', -19, 4, 'Pilot', 4, 'George Lucas', 'Ça va péter');
	INSERT INTO PERSONNAGES VALUES ('Chawbacca', 'masculin', 'wookie', 'empire', -19, 4, 'Pilot', 5, 'George Lucas', 'Je suis ton père');
	INSERT INTO PERSONNAGES VALUES ('Chawbacca', 'masculin', 'wookie', 'empire', -19, 4, 'Pilot', 6, 'George Lucas', 'Ça va encore péter');
	INSERT INTO PERSONNAGES VALUES ('Chawbacca', 'masculin', 'wookie', 'premier ordre', 4, 40, 'Pilote', 7, 'J. J. Abrams', 'Le premier ordre à la traine');
	INSERT INTO PERSONNAGES VALUES ('Luke Skywalker', 'masculin', 'humain', 'empire', -19, 4, 'Jedi', 4, 'George Lucas', 'Ça va péter');
	INSERT INTO PERSONNAGES VALUES ('Luke Skywalker', 'masculin', 'humain', 'empire', -19, 4, 'Jedi', 5, 'George Lucas', 'Je suis ton père');
	INSERT INTO PERSONNAGES VALUES ('Luke Skywalker', 'masculin', 'humain', 'empire', -19, 4, 'Jedi', 6, 'George Lucas', 'Ça va encore péter');
	INSERT INTO PERSONNAGES VALUES ('Leia Organa', 'féminin', 'humain', 'empire', -19, 4, 'Jedi', 4, 'George Lucas', 'Ça va péter');
	INSERT INTO PERSONNAGES VALUES ('Leia Organa', 'féminin', 'humain', 'empire', -19, 4, 'Jedi', 5, 'George Lucas', 'Je suis ton père');
	INSERT INTO PERSONNAGES VALUES ('Leia Organa', 'féminin', 'humain', 'empire', -19, 4, 'Jedi', 6, 'George Lucas', 'Ça va encore péter');
	INSERT INTO PERSONNAGES VALUES ('Leia Organa', 'féminin', 'humain', 'premier ordre', 4, 40, 'Jedi', 7, 'J. J. Abrams', 'Le premier ordre à la traine');
	INSERT INTO PERSONNAGES VALUES ('Yoda', 'masculin', 'Inconnu', 'empire', -19, 4, 'Jedi', 5, 'George Lucas', 'Je suis ton père');
	INSERT INTO PERSONNAGES VALUES ('Yoda', 'masculin', 'Inconnu', 'empire', -19, 4, 'Jedi', 6, 'George Lucas', 'Ça va encore péter');
	INSERT INTO PERSONNAGES VALUES ('Yoda', 'masculin', 'Inconnu', 'ancienne république', -25000, -19, 'Jedi', 1, 'George Lucas', 'Anakin découvre la Force');
	INSERT INTO PERSONNAGES VALUES ('Yoda', 'masculin', 'Inconnu', 'ancienne république', -25000, -19, 'Jedi', 2, 'George Lucas', 'Un si beau couple');
	INSERT INTO PERSONNAGES VALUES ('Yoda', 'masculin', 'Inconnu', 'ancienne république', -25000, -19, 'Jedi', 3, 'George Lucas', 'Coup de chaud pour le seigneur Vador');
	INSERT INTO PERSONNAGES VALUES ('Anakin Skywalker', 'masculin', 'humain', 'ancienne république', -25000, -19, 'Jedi', 1, 'George Lucas', 'Anakin découvre la Force');
	INSERT INTO PERSONNAGES VALUES ('Anakin Skywalker', 'masculin', 'humain', 'ancienne république', -25000, -19, 'Jedi', 2, 'George Lucas', 'Un si beau couple');
	INSERT INTO PERSONNAGES VALUES ('Anakin Skywalker', 'masculin', 'humain', 'ancienne république', -25000, -19, 'Jedi', 3, 'George Lucas', 'Coup de chaud pour le seigneur Vador');
	INSERT INTO PERSONNAGES VALUES ('Dark Vador', 'masculin', 'humain', 'empire', -19, 4, 'Sith', 4, 'George Lucas', 'Ça va péter');
	INSERT INTO PERSONNAGES VALUES ('Dark Vador', 'masculin', 'humain', 'empire', -19, 4, 'Sith', 5, 'George Lucas', 'Je suis ton père');
	INSERT INTO PERSONNAGES VALUES ('Dark Vador', 'masculin', 'humain', 'empire', -19, 4, 'Sith', 6, 'George Lucas', 'Ça va encore péter');
	INSERT INTO PERSONNAGES VALUES ('Obi-Wan Kenobi', 'masculin', 'humain', 'ancienne république', -25000, -19, 'Jedi', 1, 'George Lucas', 'Anakin découvre la Force');
	INSERT INTO PERSONNAGES VALUES ('Obi-Wan Kenobi', 'masculin', 'humain', 'ancienne république', -25000, -19, 'Jedi', 2, 'George Lucas', 'Un si beau couple');
	INSERT INTO PERSONNAGES VALUES ('Obi-Wan Kenobi', 'masculin', 'humain', 'ancienne république', -25000, -19, 'Jedi', 3, 'George Lucas', 'Coup de chaud pour le seigneur Vador');
	INSERT INTO PERSONNAGES VALUES ('Qui-Gon Jinn', 'masculin', 'humain', 'ancienne république', -25000, -19, 'Jedi', 1, 'George Lucas', 'Anakin découvre la Force');
	INSERT INTO PERSONNAGES VALUES ('Dark Maul', 'masculin', 'Zabrak', 'ancienne république', -25000, -19, 'Sith', 1, 'George Lucas', 'Anakin découvre la Force');
	INSERT INTO PERSONNAGES VALUES ('Palpatine', 'masculin', 'humain', 'ancienne république', -25000, -19, 'Sith', 1, 'George Lucas', 'Anakin découvre la Force');
	INSERT INTO PERSONNAGES VALUES ('Palpatine', 'masculin', 'humain', 'ancienne république', -25000, -19, 'Sith', 2, 'George Lucas', 'Un si beau couple');
	INSERT INTO PERSONNAGES VALUES ('Palpatine', 'masculin', 'humain', 'ancienne république', -25000, -19, 'Sith', 3, 'George Lucas', 'Coup de chaud pour le seigneur Vador');
	INSERT INTO PERSONNAGES VALUES ('Palpatine', 'masculin', 'humain', 'empire', -19, 4, 'Sith', 5, 'George Lucas', 'Je suis ton père');
	INSERT INTO PERSONNAGES VALUES ('Palpatine', 'masculin', 'humain', 'empire', -19, 4, 'Sith', 6, 'George Lucas', 'Ça va encore péter');
	INSERT INTO PERSONNAGES VALUES ('Padmé Amidala', 'féminin', 'humain', 'ancienne république', -25000, -19, 'Politicien', 1, 'George Lucas', 'Anakin découvre la Force');
	INSERT INTO PERSONNAGES VALUES ('Padmé Amidala', 'féminin', 'humain', 'ancienne république', -25000, -19, 'Politicien', 2, 'George Lucas', 'Un si beau couple');
	INSERT INTO PERSONNAGES VALUES ('Padmé Amidala', 'féminin', 'humain', 'ancienne république', -25000, -19, 'Politicien', 3, 'George Lucas', 'Coup de chaud pour le seigneur Vador');
	INSERT INTO PERSONNAGES VALUES ('R2-D2', 'aucun', 'droide', 'ancienne république', -25000, -19, 'Réparateur', 1, 'George Lucas', 'Anakin découvre la Force');
	INSERT INTO PERSONNAGES VALUES ('R2-D2', 'aucun', 'droide', 'ancienne république', -25000, -19, 'Réparateur', 2, 'George Lucas', 'Un si beau couple');
	INSERT INTO PERSONNAGES VALUES ('R2-D2', 'aucun', 'droide', 'ancienne république', -25000, -19, 'Réparateur', 3, 'George Lucas', 'Coup de chaud pour le seigneur Vador');
	INSERT INTO PERSONNAGES VALUES ('R2-D2', 'aucun', 'droide', 'empire', -19, 4, 'Réparateur', 4, 'George Lucas', 'Ça va péter');
	INSERT INTO PERSONNAGES VALUES ('R2-D2', 'aucun', 'droide', 'empire', -19, 4, 'Réparateur', 5, 'George Lucas', 'Je suis ton père');
	INSERT INTO PERSONNAGES VALUES ('R2-D2', 'aucun', 'droide', 'empire', -19, 4, 'Réparateur', 6, 'George Lucas', 'Ça va encore péter');
	INSERT INTO PERSONNAGES VALUES ('C-3PO', 'aucun', 'droide', 'ancienne république', -25000, -19, 'Traducteur', 1, 'George Lucas', 'Anakin découvre la Force');
	INSERT INTO PERSONNAGES VALUES ('C-3PO', 'aucun', 'droide', 'ancienne république', -25000, -19, 'Traducteur', 2, 'George Lucas', 'Un si beau couple');
	INSERT INTO PERSONNAGES VALUES ('C-3PO', 'aucun', 'droide', 'ancienne république', -25000, -19, 'Traducteur', 3, 'George Lucas', 'Coup de chaud pour le seigneur Vador');
	INSERT INTO PERSONNAGES VALUES ('C-3PO', 'aucun', 'droide', 'empire', -19, 4, 'Traducteur', 4, 'George Lucas', 'Ça va péter');
	INSERT INTO PERSONNAGES VALUES ('C-3PO', 'aucun', 'droide', 'empire', -19, 4, 'Traducteur', 5, 'George Lucas', 'Je suis ton père');
	INSERT INTO PERSONNAGES VALUES ('C-3PO', 'aucun', 'droide', 'empire', -19, 4, 'Traducteur', 6, 'George Lucas', 'Ça va encore péter');
	INSERT INTO PERSONNAGES VALUES ('Jango Fett', 'masculin', 'humain', 'ancienne république', -25000, -19, 'Chasseur de primes', 2, 'George Lucas', 'Un si beau couple');
	INSERT INTO PERSONNAGES VALUES ('Boba Fett', 'masculin', 'humain', 'empire', -19, 4, 'Chasseur de primes', 5, 'George Lucas', 'Je suis ton père');
	INSERT INTO PERSONNAGES VALUES ('Boba Fett', 'masculin', 'humain', 'empire', -19, 4, 'Chasseur de primes', 6, 'George Lucas', 'Ça va encore péter');


	COMMIT;
