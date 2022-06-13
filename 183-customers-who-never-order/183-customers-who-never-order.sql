/* Write your T-SQL query statement below */
SELECT name AS Customers
FROM Customers
WHERE id not in (SELECT customerID FROM Orders)