
with t1 as(
select f1.shipment_id, f1.flavor, f1.total_order, f2.ingredient_type
from first_half as f1 join icecream_info as f2
    on f1.FLAVOR = f2.FLAVOR)
    
select ingredient_type, sum(total_order) as TOTAL_ORDER from t1
group by ingredient_type
order by total_order asc