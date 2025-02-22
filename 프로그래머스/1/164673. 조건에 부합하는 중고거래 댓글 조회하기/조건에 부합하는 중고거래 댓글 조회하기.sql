-- 코드를 입력하세요
SELECT TITLE,u1.BOARD_ID,REPLY_ID,u2.WRITER_ID,u2.CONTENTS,left(u2.CREATED_DATE,10)
from USED_GOODS_BOARD as u1 inner join USED_GOODS_REPLY as u2 on u1.BOARD_ID = u2.BOARD_ID
where u1.created_date like '2022-10%'# 게시글은2022년10월
order by u2.created_date asc, u1.title asc