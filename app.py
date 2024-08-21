from flask import Flask, render_template
from flask_mysqldb import MySQL
from config import Config
import MySQLdb.cursors
import traceback
import os

app = Flask(__name__,
            static_folder=os.path.join(os.getcwd(), 'client/static'),
            template_folder=os.path.join(os.getcwd(), 'client/templates'))
app.config.from_object(Config)

app.config['MYSQL_USER'] = 'root'
app.config['MYSQL_PASSWORD'] = '1234'  # root 계정의 비밀번호


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
        traceback.print.exc()  # 자세한 에러 스택 출력
        return "An error occurred."

@app.route('/test_db')
def test_db():
    try:
        cur = mysql.connection.cursor()
        cur.execute("SELECT 1")
        result = cur.fetchone()
        cur.close()
        return f"MySQL is working: {result}"
    except Exception as e:
        print(f"Error: {e}")
        traceback.print_exc()
        return "Database connection failed."

if __name__ == '__main__':
    app.run(debug=True)