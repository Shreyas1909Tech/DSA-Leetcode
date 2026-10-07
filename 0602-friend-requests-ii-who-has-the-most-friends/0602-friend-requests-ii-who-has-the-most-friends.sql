# Write your MySQL query statement below
WITH myCTE AS (
    Select requester_id AS id from RequestAccepted
    UNION ALL
    Select accepter_id AS id from RequestAccepted
)
SELECT id , COUNT(*) AS num
FROM myCTE
GROUP BY id
ORDER BY num DESC
LIMIT 1 