###Qt TCP
####QTcpSocket
QTcpSocket的工作步骤如下：
1. 连接到服务器
```
	tcpSocket.connectToHost(QHostAddress::LocalHost, 8080);
```
    这里将主机设为自己的计算机.如果连接成功，QTcpSocket对象会发射connected()信号，若失败，发射error(QAbstractSocket::SocketError)信号。
    这里可以调用waitForConnected()来判断是否连接成功。
2. 连接成功后，调用槽函数发送请求信息
```
	QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << quint16(0) << quint8("S") << lineEdit.text();
    out.device()->seek(0);
    out << quint(block.size() - sizeof(quint16));
	tcpSocket.write(block);
```
    这个请求的格式为
    |请求格式|解释|
    |---|---|
    |quint16|字节数据中块的大小（不包括本身）|
    |quint8|请求指令类型(总为S)|
    |QString|数据|

	最后用write()向服务器发送请求.
3. 接收到服务器返回的信息
	当tcpSocket接收到数据之后，会发射readyRead()信号，之后我们就可以处理接收到的数据。
    数据的格式为：数据大小+数据。
```
	QDataStream in(&tcpSocket);
```
	还有很多方法能够读取数据，如readLine()等。
4. 关闭连接
	当错误或者结束时都可以调用以下函数来关闭socket.
```
	tcpSocket.close();
```

####QTcpServer
1. 建立服务器
```
	QTcpServer tcpServer;
    if (!server.listen(QHostAddress::Any, 8080))
	{
    	qDebug() << "failed to bind to port";
        return;
	}
```
	通过调用listen()函数来启动服务器，它将具有我们想要接收的连接的IP地址和端口号。这里的QHostAddress::Any表示在本地主机上的任意IP接口。

2. 等待客户端连接
```
	incomingConnection(int sockretId)
    {
        QTcpSocket *tcpSocket = new QTcpSocket(this);
        tcpSocket->setSocketDescroptor(socketId);
    }
```
	只要有一个客户端试图连接到服务器正在监听的端口，这个函数就会被调用。
	在incomintConetction()中，创建一个QTcpSocket对象用来和客户端进行交流。当连接结束时，该对象会自动删除。

3. 数据读写