# Write your MySQL query statement below


# select firstName, lastName,city,state from Person p left outer join Address a on p.personID = a.personID 

# SELECT 
#     p.firstName,
#     p.lastName,
#     (SELECT a.city FROM Address a WHERE a.personId = p.personId) AS city,
#     (SELECT a.state FROM Address a WHERE a.personId = p.personId) AS state
# FROM Person p;


select firstName, lastName , city , state 
from Person p left join Address a on p.personID = a.personID