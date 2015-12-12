
SELECT t.code, t.name
FROM towns t, departments d
WHERE t.department = d.code
AND d.name = 'Isère';
