# Write your MySQL query statement below
SELECT name
FROM Employee 
WHERE id IN(
SELECT managerID from Employee 
GROUP BY managerId 
HAVING COUNT(id) >=5)