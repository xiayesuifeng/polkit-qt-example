# polkit-qt-example
实现利用polkit+dbus进行root操作实例

源码分析：http://morfans.cn/archives/2456

# 依赖
Qt5

polkit-qt5

# 编译(需要安装cmake)
git clone https://github.com/1377195627/polkit-qt-example.git

cd polkit-qt-example

mkdir build

cd build

cmake ..

make -j8


# 运行
运行cpserver.sh脚本将需要的配置文件复制进系统

手动运行sudo polkit-qt-example-daemon

(在systemBus注册服务死活无法自启polkit-qt-example-daemon，sessionBus可以自启，但是不是root用户运行，原因未知)

再运行polkit-qt-example，本实例一共两个polkit请求，一个运行时就请求daemon返回Hello DBus文本，第二个是请求在/etc下写入test文件（运行完自行删除）

# 删除复制进系统的配置文件
运行rmserver.sh