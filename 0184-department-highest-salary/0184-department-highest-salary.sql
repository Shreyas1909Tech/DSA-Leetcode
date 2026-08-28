# Write your MySQL query statement below
SELECT D.name as Department, E.name as Employee,E.salary as Salary 
FROM Employee e
JOIN Department d on e.departmentId= d.id
WHERE e.salary=
(
    SELECT MAX(salary)
    FROM Employee
    WHERE departmentId=e.departmentID
);