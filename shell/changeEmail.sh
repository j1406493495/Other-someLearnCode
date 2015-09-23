#! /bin/sh

rm sendTestMail.sh
wget 192.168.122.30/sendTestMail.sh
chmod +x sendTestMail.sh
./sendTestMail.sh whjin@grandstream.cn mail.conf pic pic.png
