FROM ubuntu


RUN apt-get -y update

RUN apt -y install build-essential && apt-get -y install manpages-dev

COPY ./ /lem_in_

WORKDIR /lem_in