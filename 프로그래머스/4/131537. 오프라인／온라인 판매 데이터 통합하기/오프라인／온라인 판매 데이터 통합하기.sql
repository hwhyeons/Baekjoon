-- 코드를 입력하세요
with ut as
(SELECT SALES_DATE,PRODUCT_ID,USER_ID,SALES_AMOUNT from ONLINE_SALE
union all
select sales_date, product_id,null as USER_ID,sales_amount from offline_sale),
T2 as 
(
select SALES_DATE,PRODUCT_ID,USER_ID,SALES_AMOUNT from ut
where year(SALES_DATE) = 2022 and month(SALES_DATE) = 3
# where product_id = 17 # temp
order by sales_date asc, product_id asc, user_id asc
)

select DATE_FORMAT(SALES_DATE,'%Y-%m-%d') as SALES_DATE,PRODUCT_ID,USER_ID,SALES_AMOUNT from t2
# select DATE_FORMAT(SALES_DATE,'%Y-%m-%d') as SALES_DATE,PRODUCT_ID,IFNULL(USER_ID,'NULL') as USER_ID,SALES_AMOUNT from t2

# IFNULL(USER_ID,'NULL')