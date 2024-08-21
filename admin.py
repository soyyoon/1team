from flask import Flask, render_template, jsonify
from flask_mysqldb import MySQL
from config import Config
import MySQLdb.cursors
import traceback
import os

admin_app = Flask(__name__) 
admin_app.config.from_object(Config)

admin_app.config['MYSQL_USER'] = 'root'
admin_app.config['MYSQL_PASSWORD'] = '1234'

mysql = MySQL(admin_app)

admin_app.config['MYSQL_CURSORCLASS'] = 'DictCursor'

@admin_app.route('/') 
def manage():
    try:
        cur = mysql.connection.cursor()
        cur.execute('SELECT * FROM items')
        items = cur.fetchall()
        cur.close()
        return render_template('manage.html', items=items) 

    except Exception as e:
        print(f"Error: {e}") 
        return "An error occurred."

@admin_app.route('/decrease_quantity/<int:item_id>', methods=['POST'])
def decrease_quantity(item_id):
    try:
        cur = mysql.connection.cursor()
        cur.execute('UPDATE items SET available_quantity = available_quantity - 1 WHERE id = %s AND available_quantity > 0', (item_id,))
        mysql.connection.commit()
        cur.close()
        return jsonify({'success': True})
    except Exception as e:
        return jsonify({'success': False, 'message': str(e)})

@admin_app.route('/increase_quantity/<int:item_id>', methods=['POST'])
def increase_quantity(item_id):
    try:
        cur = mysql.connection.cursor()
        cur.execute('UPDATE items SET available_quantity = available_quantity + 1 WHERE id = %s', (item_id,))
        mysql.connection.commit()
        cur.close()
        return jsonify({'success': True})
    except Exception as e:
        return jsonify({'success': False, 'message': str(e)})

if __name__ == '__main__':
    admin_app.run(debug=True, port=5001)  # 다른 포트 번호 사용 (예: 5001)