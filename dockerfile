FROM ubuntu
ADD docker /data/
ENV PATH=/data:$PATH
CMD /data/a.out



