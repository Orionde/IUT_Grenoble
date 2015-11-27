--Exercice 1
--1)
BEGIN;
	insert into MONITEUR values(10, 'lacroix', 'franck', 'courchevel', '0490584525');
		--On insère des trucs dans la table MONITEUR

	select * from MONITEUR where nummono = 10;
	--On fait un select de la valeur insérée
ROLLBACK;--On fait un ROLLBACK : annuler action
	select * from MONITEUR where nummono = 10;
	--On selectlectionne la même chose : on ne trouve rien car l'action a été annulée.

--2
BEGIN;
insert into MONITEUR values(10, 'lacroix', 'franck', 'courchevel', '0490584525'); --On insère un truc 
	select * from MONITEUR; --On selectionne le truc qu'on a inséré, ça marche
COMMIT;--Valider la transaction
select * from MONITEUR; --ça marche aussi, vu qu'on a validé.

--3
BEGIN;
insert into MONITEUR
		values(10, 'lacroix', 'franck', 'courchevel', '0490584525');

insert into MONITEUR
		values(11, 'labanniere', 'maurice', 'courchevel', '0478954566');

insert into MONITEUR
		values(12, 'lavallee', 'maria', 'les deux alpes', '0445657898');

COMMIT;--On valide, modifications prise en compte

select * from MONITEUR;

delete from MONITEUR where nummono = 11;

insert into MONITEUR
		values(13, 'lavoile', 'denise', 'les deux alpes', '0478456598');
select * from MONITEUR;
--Toutes ces instructions sont prise en compte,
--elles ne sont pas dans la transaction

BEGIN;
update MONITEUR set nummono=14 where nummono=13;
update MONITEUR set nom='larousse' where nom='lavallee';
select * from MONITEUR;
ROLLBACK;--Ces instructions ne sont pas prise en compte(rollback)
select * from MONITEUR;

--Exercice 2
--1
BEGIN;
insert into MONITEUR values
	(null, 'lapierre', 'éric', 'chamrousse', '0490584525');
select * from MONITEUR;
COMMIT;
select * from MONITEUR;

--2
BEGIN;
insert into ELEVE(nom, prenom, datenaissance, adressestation, mobile)
	values('gigi', 'lebronze', '05/12/1971', 'sur le télésiège', '0789889988');
	select * from ELEVE;
	insert into INSCRIT values('gigi', 1);
COMMIT;
	select * from ELEVE;
	select * from INSCRIT;
