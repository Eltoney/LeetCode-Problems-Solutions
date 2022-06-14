/* Write your T-SQL query statement below */
UPDATE SALARY
SET sex = CASE WHEN sex = 'f' Then 'm' ELSE 'f' END