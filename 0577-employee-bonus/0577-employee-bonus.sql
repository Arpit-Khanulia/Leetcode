# Write your MySQL query statement below


select e.name, b.bonus
FROM Employee e left join Bonus b on e.empID = b.empID
where bonus <1000 or bonus is null