# Write your MySQL query statement below
# https://www.codeproject.com/Articles/33052/Visual-Representation-of-SQL-Joins
SELECT Person.FirstName, Person.LastName, Address.City, Address.State from Person LEFT JOIN Address on Person.PersonId = Address.PersonId;
