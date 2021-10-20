# daemon runs in the background
# run something like tail /var/log/derogoldcashcashd/current to see the status
# be sure to run with volumes, ie:
# docker run -v $(pwd)/derogoldcashd:/var/lib/derogoldcashd -v $(pwd)/wallet:/home/derogoldcash --rm -ti derogoldcash:0.6.0
ARG base_image_version=0.6.0
FROM phusion/baseimage:$base_image_version

ADD https://github.com/just-containers/s6-overlay/releases/download/v1.21.2.2/s6-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/s6-overlay-amd64.tar.gz -C /

ADD https://github.com/just-containers/socklog-overlay/releases/download/v2.1.0-0/socklog-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/socklog-overlay-amd64.tar.gz -C /

ARG derogoldcash_BRANCH=master
ENV derogoldcash_BRANCH=${TURTLECOIN_BRANCH}

# install build dependencies
# checkout the latest tag
# build and install
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      python-dev \
      gcc-9.3 \
      g++-9.3 \
      git cmake \
      libboost1.69-all-dev && \
    git clone https://github.com/derogoldcash/derogoldcash.git /src/derogoldcash && \
    cd /src/derogoldcash && \
    git checkout $derogoldcash_BRANCH && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_FLAGS="-g0 -Os -fPIC -std=gnu++11" .. && \
    make -j$(nproc) && \
    mkdir -p /usr/local/bin && \
    cp src/derogoldcashd /usr/local/bin/derogoldcashd && \
    cp src/zedwallet-beta /usr/local/bin/zedwallet-beta && \
    cp src/miner /usr/local/bin/miner && \
    strip /usr/local/bin/derogoldcashd && \
    strip /usr/local/bin/zedwallet-beta && \
    strip /usr/local/bin/miner && \
    cd / && \
    rm -rf /src/derogoldcash && \
    apt-get remove -y build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost1.69-all-dev && \
    apt-get autoremove -y && \
    apt-get install -y  \
      libboost-system1.69.0 \
      libboost-filesystem1.69.0 \
      libboost-thread1.69.0 \
      libboost-date-time1.69.0 \
      libboost-chrono1.69.0 \
      libboost-regex1.69.0 \
      libboost-serialization1.69.0 \
      libboost-program-options1.69.0 \
      libicu66

# setup the derogoldcashd service
RUN useradd -r -s /usr/sbin/nologin -m -d /var/lib/derogoldcashd derogoldcashd && \
    useradd -s /bin/bash -m -d /home/derogoldcash derogoldcashd && \
    mkdir -p /etc/services.d/derogoldcashd/log && \
    mkdir -p /var/log/derogoldcashd && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/derogoldcashd/run && \
    echo "fdmove -c 2 1" >> /etc/services.d/derogoldcashd/run && \
    echo "cd /var/lib/derogoldcashd" >> /etc/services.d/derogoldcashd/run && \
    echo "export HOME /var/lib/derogoldcashd" >> /etc/services.d/derogoldcashd/run && \
    echo "s6-setuidgid derogoldcashd /usr/local/bin/derogoldcashd" >> /etc/services.d/derogoldcashd/run && \
    chmod +x /etc/services.d/derogoldcashd/run && \
    chown nobody:nogroup /var/log/derogoldcashd && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/derogoldcashd/log/run && \
    echo "s6-setuidgid nobody" >> /etc/services.d/derogoldcashd/log/run && \
    echo "s6-log -bp -- n20 s1000000 /var/log/derogoldcashd" >> /etc/services.d/derogoldcashd/log/run && \
    chmod +x /etc/services.d/derogoldcashd/log/run && \
    echo "/var/lib/derogoldcashd true derogoldcashd 0644 0755" > /etc/fix-attrs.d/derogoldcashd-home && \
    echo "/home/derogoldcash true turtlecoin 0644 0755" > /etc/fix-attrs.d/derogoldcash-home && \
    echo "/var/log/derogoldcashd true nobody 0644 0755" > /etc/fix-attrs.d/derogoldcashd-logs

VOLUME ["/var/lib/derogoldcashd", "/home/derogoldcash","/var/log/derogoldcashd"]

ENTRYPOINT ["/init"]
CMD ["/usr/bin/execlineb", "-P", "-c", "emptyenv cd /home/derogoldcash export HOME /home/derogoldcash s6-setuidgid derogoldcash /bin/bash"]
