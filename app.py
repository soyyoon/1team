import MySQLdb.cursors
from flask import Flask, render_template
from flask_mysqldb import MySQL
<<<<<<< HEAD
from config import Config

app = Flask(__name__, template_folder='templates', static_folder='static')
app.config.from_object(Config)

mysql = MySQL(app)

=======
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

>>>>>>> 5e4112b407d67b13f9a6cd149379471275d1a08a
@app.route('/')
def index():
    try:
        # 데이터베이스 커서 열기
        cur = mysql.connection.cursor()
<<<<<<< HEAD
        
        # rental_items 테이블에서 모든 데이터를 가져옴
        cur.execute('SELECT * FROM rental_items')
        
        # 데이터를 가져와서 저장
=======
        cur.execute('SELECT * FROM rental_items')
>>>>>>> 5e4112b407d67b13f9a6cd149379471275d1a08a
        items = cur.fetchall()
        
        # 커서 닫기
        cur.close()
        
        # 데이터를 'index.html' 템플릿으로 전달
        return render_template('index.html', items=items)

    except Exception as e:
<<<<<<< HEAD
=======
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
>>>>>>> 5e4112b407d67b13f9a6cd149379471275d1a08a
        print(f"Error: {e}")
        return "An error occurred."

if __name__ == '__main__':
    app.run(debug=True)
