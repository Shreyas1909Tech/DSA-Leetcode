# Write your MySQL query statement below
WITH new_table AS (SELECT D.name as Department, E.name as Employee, E.salary as Salary,
DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.salary DESC) AS ranking
FROM Employee e
LEFT JOIN Department d
ON e.departmentId=d.id
)
SELECT Department,Employee,Salary
From new_table
WHERE ranking<=3;