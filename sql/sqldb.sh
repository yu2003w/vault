#!/bin/sh
if [ $# != 2 ]; then
  echo "Usage: sqldb.sh start | shutdown | clean | load"
  echo "Please specify proper parameters"
fi
if [ "$1"x = "start"x ]; then
  # store data/log files in local directories
  mkdir -p $(pwd)/mysql/data $(pwd)/mysql/schema $(pwd)/logs/mysql
  podman run --rm --name sqltest --hostname sqltest -v $(pwd)/mysql/data:/var/lib/mysql \
      -v $(pwd)/mysql/schema/:/root/mysql/schema/ -v $(pwd)/logs/mysql/:/var/log/mysql/ \
      -p 13306:3306 -e MYSQL_ROOT_PASSWORD=mysql -d mysql:8.0-debian \
      --group-concat-max-len=8192 \
      --log-error=/var/log/mysql/mysqld.log \
      --general_log=1 --general_log_file /var/log/mysql/gen.log \
      --slow_query_log=1  --slow_query_log_file /var/log/mysql/slow.log

  if [ $? != 0 ]; then
    echo "failed to launch mysql 8.0 locally."
    exit 1
  fi
elif [ "$1"x = "shutdown"x ]; then
  podman stop sqltest 
elif [ "$1"x = "clean"x ]; then
  echo "clean test data"
elif [ "$1"x = "load"x ]; then
  echo "loading test data into database"
else
  echo "unrecognized parameter $1"
  exit 1
fi
