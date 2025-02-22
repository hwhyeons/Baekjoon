-- 코드를 입력하세요
SELECT distinct(os1.user_id),os2.product_id
from ONLINE_SALE as os1 inner join ONLINE_SALE as os2
    on os1.user_id = os2.user_id and os1.product_id = os2.product_id
        and os1.sales_date != os2.sales_date
order by os1.user_id asc, os1.product_id desc
