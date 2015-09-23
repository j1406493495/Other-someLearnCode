###Qt XML 读写
此文为阅读《《Qt4编程之XML》》笔记
####读取XML

##### QXmlStreamReader 读取XML文档的快速解析器
QXmlStreamReader是Qt中读取XML文档最快且最简单的方式。
QXmlStreamReader根据记号工作，每次调用readNext()函数就会到下一个记号，用getter函数就可读取当前记号。
 | 记号 | 示例 | getter函数 |
 |----|----|----|
 |startDocument|N/A|isStandaloneDocument()|
 |EndDocument|N/A|isStandaloneDocument()|
 |StartElement|&lt;item&gt;|name()|
 |EndElement|&lt;\item&gt;|name()|
 |Characters|AT&amp;T|text()|
 |Invaild|>&<!|error(),errorString()|

例如：
```
<doc>
    <quote>hello world</quote>
</doc>
```
使用readNext得到的结果
>startDocument
>startElement (name() == "doc")
>startElement (name() == "quote")
>characters (text() == "hello world")
>endElement (name() == "quote")
>endElement (name() == "doc")
>endDocument

每次调用readNext(), 可以用isStartElement(), isCharacters()或直接用state()来测试当前记号的类型。

使用QXmlStreamReader可用以下方式
```
QXmlStreamReader xmlReader;
QFile file(fileName);
xmlReader.setDevice(&file);
...
xmlReader.readNext();
while (!xmlReader.atEnd())
{
  if (xmlReader.isStartElement())
  {
    if (xmlReader.name() == "doc")
    {
    }
    else
    {
      xmlReader.raiseError(tr("error"));
    }
  }
  else
  {
     xmlReader.readNext();
  }
}
```

##### DOM 文档对象模型
```
<doc>
    <quote>hello</quote>
    <tarns>world</tarns>
</doc>
```
利用DOM可以将上面xml文档建立模型如下
- Document
 - Element (doc)
   - Element (quote)
     - text ("hello")
   - Element (tarns)
     - text ("world")

使用DOM可以通过以下方式
```
QFile file(fileName);
QDomDocument doc;
if (!doc.setContent(&file))
{
    qDebug() << "error";
    return;
}

QDomElement root = doc.documentElement();
if (root.tagName() == "doc")
{
  QDomNode child = root.firstChild();
  while (!child.isNull())
  {
    if (child.toElement().tagName() == "quote") 
    {
        if (child.toElement().text() == "hello")
        {}
    }
    else if (child.toElement().tagName() == "trans")
    {}
    child = child.nextSibling();
  }
}
```
QDomNode类可以存储任何类型的节点。如果想进一步处理一个节点，首先必须把它转换为正确的数据类型。

####写入XML
#####QXmlStreamWriter
使用QXmlStreamWriter是目前最简单易行的方式，使用方式如下：
```
QFile file(fileName);
if (!file.open(QFile::WriteOnly | QFile::Text))
{return;}

QXmlStreamWriter xmlWriter(&file);
xmlWriter.setAutoFormatting(true);

xmlWriter.writeStartDocument();
xmlWriter.writeStartElement("doc");
xmlWriter.writeTextElement("quote", “hello");
xmlWriter.writeTextElement("trans", "world");
xmlWriter.writeEndElement();
xmlWriter.writeEndDocument();
```
如果项中有子项，就对每个子项调用writeIndexEntry().
#####DOM
尽管QXmlStreamWriter是写入xml最容易，最安全的方式，但如果已经在一个DOM树中有XML文档的时候，则需要在QDomDocument对象上调用save()函数并要求这个DOM树输出相关的XML即可。
```
const int Indent = 4;
QDomDocument doc;
...
QTextStream out(&file);
QDomNode xmlNode = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"ISO-8859-1\"");
doc.insertBefore(xmlNode, doc.firstChild());
doc.save(out, Indent);
```