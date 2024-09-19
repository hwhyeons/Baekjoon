import re
s=input()
# s='<main><div title="title_name_1"><p>paragraph 1</p><p>paragraph 2 <i>Italic Tag</i> <br > </p><p>paragraph 3 <b>Bold Tag</b> end.</p></div><div title="title_name_2"><p>paragraph 4</p><p>paragraph 5 <i>Italic Tag 2</i> <br > end.</p></div></main>'
# s='<div title="title_name_2"><p>paragraph 4</p><p>paragraph 5 <i>Italic Tag 2</i> <br > end.</p></div></main>'
s=s.strip().replace("<main>","").replace("</main>","")
divs = re.findall(r'<div.+?</div>',s)
for div in divs:
    # get div title
    r_title = r'<div title="(.+?)">'
    title_str = re.match(r_title,div).group(1)
    print(f"title : {title_str}")

    # <p>paragraph 1</p><p>paragraph 2 <i>Italic Tag</i> <br > </p><p>paragraph 3 <b>Bold Tag</b> end.</p>
    removed_title_str = div.replace(f'<div title="{title_str}">',"").replace("/div>","").strip()
    r_paragraph = r'<p>.+?</p>'
    for paragraph in re.findall(r_paragraph,removed_title_str):
        reg_tag = r'<.+?>' # 태그 없애기
        removed_tag_paragraph = re.sub(reg_tag,'',paragraph)
        replace_more_two_blanks = re.sub(r' {2,}',' ',removed_tag_paragraph)
        strip_str = replace_more_two_blanks.strip()
        print(strip_str)

