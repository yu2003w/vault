#! /bin/sh
nohup python3 manage.py runmodwsgi --port=80 --host=192.168.0.104 --server-root=/tmp/syhealth --user www-data --group www-data &
