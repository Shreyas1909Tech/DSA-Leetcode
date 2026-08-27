# Write your MySQL query statement below
SELECT name as Customers from Customers
LEFT JOIN Orders
ON customers.id= orders.customerId
WHERE orders.customerID IS NULL; 