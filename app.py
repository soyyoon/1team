from flask import Flask, render_template
from flask_mysqldb import MySQL
import MySQLdb.cursors
import traceback
import os
from werkzeug.middleware.proxy_fix import ProxyFix

# Flask 애플리케이션 생성
app = Flask(__name__,
            static_folder=os.path.join(os.getcwd(), 'static'),
            template_folder=os.path.join(os.getcwd(), 'templates'))

# Config.py에서 설정 로드
app.config.from_object('config.Config')

mysql = MySQL(app)

# 커서 클래스 설정
app.config['MYSQL_CURSORCLASS'] = 'DictCursor'

# ProxyFix 설정
app.wsgi_app = ProxyFix(app.wsgi_app, x_for=1, x_proto=1, x_host=1, x_port=1)

@app.route('/')
def index():
    try:
        cur = mysql.connection.cursor()
        cur.execute('SELECT * FROM rental_items')
        items = cur.fetchall()
        cur.close()
        return render_template('index.html', items=items)

    except Exception as e:
        print(f"Error: {e}")  # 로그에 오류 메시지를 기록합니다.
        traceback.print_exc()  # 자세한 에러 스택 출력
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
