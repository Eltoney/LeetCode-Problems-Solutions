/* 
 Please write a DELETE statement and DO NOT write a SELECT statement.
 Write your T-SQL query statement below
 */
DELETE p1 FROM Person  p1
WHERE id > 
(SELECT min(id) FROM person  p2 WHERE p2.email = p1.email GROUP by email)