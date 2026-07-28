# Write your MySQL query statement below
select p.product_id, p.new_price as price
from Products p 
join (
    select product_id,
        max(change_date) as latest_date
    from Products
    where change_date <= '2019-08-16'
    group by product_id
) t
on p.product_id = t.product_id
and p.change_date = t.latest_date

union

select product_id, 10 as price
from Products
group by product_id
having min(change_date) > '2019-08-16';