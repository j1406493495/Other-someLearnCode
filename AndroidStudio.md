###Android Studio

#####Android Studio 网络教程地址
下面是网络上写的比较好的网站链接
http://stormzhang.com/

#####搭建过程中出现的问题
1. Q:
   kvm is not installed on this machine
   A:
   缺少KVM虚拟机，Ubuntu下执行以下指令安装
     sudo apt-get install kvm
2. Q:
   the supplied javaHome seems to be invalid
   A:
   http://blog.fdlife.info/android/android-studio-the-supplied-javahome-seems-to-be-invalid.html
    此链接文章解决了该问题。是由于jdk版本不合适导致.
3. Q:
   ioctl(KVM_CREATE_VM) failed: Device or resource busy
   ko:failed to initialize KVM
   A:
   出现这个问题时我开启了virtualbox，关闭virtualbox即可允许android虚拟机。