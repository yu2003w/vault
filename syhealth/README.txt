This document is about how to setup apache httpd server with mod_wsgi and serving user uploaded files.
Prepared by Jared on May 25, 2016.

Update and check code into github repository on April 15, 2017.

Detailed procedures as below,
1, setup configration files.
python3 manage.py runmodwsgi --setup-only --reload-on-changes --port=80 --host=192.168.0.107 \
--server-root=/home/server/syhealth --user www-data --group www-data

Then all configuration files are generated under directory /home/server/syhealth/

2, edit httpd.conf in directory /home/server/syhealth

For example, health check reports is to be placed under directory /home/server/syhealth/reports.

DocumentRoot is set to /home/server/syhealth

Following conent should be appended into httpd.conf.

Alias '/reports/' '/home/server/syhealth/reports/'

<Directory '/home/server/syhealth/reports/'>
    Order allow,deny
    Allow from all
</Directory>

Noted: MEDIA_ROOT, MEDIA_URL should be keep consistent with that in settting.py. 


3, To run in production environment, --reload-on-changes shouldn't be enabled.


