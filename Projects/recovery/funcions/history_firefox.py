import os
import sqlite3


data_path = os.path.expanduser('~')+"/.mozilla/firefox/ri27ye3b.default"
history_db = os.path.join(data_path, 'places.sqlite')

c = sqlite3.connect(history_db)

cursor = c.cursor()
select_statement = "select moz_places.url, moz_places.visit_count from moz_places;"
cursor.execute(select_statement)

results = cursor.fetchall()

for url, count in results:
     print(url)

cursor.close()
