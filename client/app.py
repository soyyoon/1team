from flask import Flask, render_template
from flask_mysqldb import MySQL
from config import Config
import MySQLdb.cursors

app = Flask(__name__, static_folder='client/static', template_folder='client/templates')
app.config.from_object(Config)

mysql = MySQL(app)

app.config['MYSQL_CURSORCLASS'] = 'DictCursor'

@app.route('/')
def index():
    try:
        cur = mysql.connection.cursor()
        cur.execute('SELECT * FROM items')
        items = cur.fetchall()
        cur.close()
        return render_template('index.html', items=items)

    except Exception as e:
        print(f"Error: {e}")  # 로그에 오류 메시지를 기록합니다.
        return "An error occurred."

if __name__ == '__main__':
    app.run(debug=True)