import MySQLdb.cursors
from flask import Flask, render_template
from flask_mysqldb import MySQL
from config import Config

app = Flask(__name__, template_folder='templates', static_folder='static')
app.config.from_object(Config)

mysql = MySQL(app)

@app.route('/')
def index():
    try:
        # 데이터베이스 커서 열기
        cur = mysql.connection.cursor()
        
        # rental_items 테이블에서 모든 데이터를 가져옴
        cur.execute('SELECT * FROM rental_items')
        
        # 데이터를 가져와서 저장
        items = cur.fetchall()
        
        # 커서 닫기
        cur.close()
        
        # 데이터를 'index.html' 템플릿으로 전달
        return render_template('index.html', items=items)

    except Exception as e:
        print(f"Error: {e}")
        return "An error occurred."

if __name__ == '__main__':
    app.run(debug=True)