# Write your MySQL query statement below


# select name as Employee from Employee e where salary > (select salary from Employee m where e.managerID = m.id );


select e.name as Employee from Employee e join Employee m where e.managerID = m.id and e.salary > m.salary

