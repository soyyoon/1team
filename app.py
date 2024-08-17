from flask import Flask, render_template
from flask_mysqldb import MySQL
from config import Config

app = Flask(__name__, template_folder='templates', static_folder='static')  # static 폴더 설정 추가
app.config.from_object(Config)

mysql = MySQL(app)

@app.route('/')
def index():
    cur = mysql.connection.cursor()
    cur.execute('SELECT * FROM items')
    items = cur.fetchall()
    cur.close()
    return render_template('index.html', items=items)

if __name__ == '__main__':
    app.run(debug=True)