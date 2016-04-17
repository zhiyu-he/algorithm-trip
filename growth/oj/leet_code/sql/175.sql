#
#
# 175. Combine Two Tables
# ref: https://leetcode.com/problems/combine-two-tables/
# 
# TIPS: LEFT JOIN
#
#
SELECT p.FirstName, p.LastName, a.City, a.State FROM `Person` as p left join `Address` as a on p.PersonId = a.PersonId
