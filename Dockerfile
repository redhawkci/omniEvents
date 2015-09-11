FROM redhawkci/rpmbuild:el6

COPY . /root/rpmbuild/SOURCES/omniEvents-2.7.0
WORKDIR /root/rpmbuild/SOURCES

RUN tar zcf omniEvents-2.7.0.tar.gz omniEvents-2.7.0
RUN yum-builddep -y omniEvents-2.7.0/omniEvents.spec && \
    yum clean all

RUN rpmbuild -bb omniEvents-2.7.0/omniEvents.spec
