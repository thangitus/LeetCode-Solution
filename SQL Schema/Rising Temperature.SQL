/*
    https://leetcode.com/problems/rising-temperature/
*/

SELECT wt1.id
FROM Weather wt1,
     Weather wt2
WHERE wt1.Temperature > wt2.Temperature
  AND TO_DAYS(wt1.DATE) - TO_DAYS(wt2.DATE) = 1
