
SELECT distinct t1.REST_ID,REST_NAME,FOOD_TYPE,FAVORITES,ADDRESS,
    round((avg(REVIEW_SCORE) over (partition by t2.REST_ID)),2) as SCORE
    from REST_INFO as t1 join REST_REVIEW as t2 on t1.REST_ID = t2.REST_ID
where ADDRESS like '서울%'
# group by t1.REST_ID,REST_NAME,FOOD_TYPE,FAVORITES,ADDRESS
order by SCORE desc, FAVORITES desc

# select * from REST_REVIEW order by REST_ID