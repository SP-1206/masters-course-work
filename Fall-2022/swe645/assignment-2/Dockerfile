FROM tomcat:latest
RUN cp -r $CATALINA_HOME/webapps.dist/* $CATALINA_HOME/webapps/
ADD final.war $CATALINA_HOME/webapps/
RUN chmod 0777 $CATALINA_HOME/webapps/final.war
EXPOSE 8080
RUN sed -i '/^<\/tomcat-users>/i <role rolename="manager-gui"\/> \
<user username="man" password="man" roles="manager-gui"\/>' $CATALINA_HOME/conf/tomcat-users.xml
RUN sed -i '/<Valve className=.*'/d $CATALINA_HOME/webapps/manager/META-INF/context.xml
RUN sed -i '/allow=.*'/d $CATALINA_HOME/webapps/manager/META-INF/context.xml
CMD ["catalina.sh", "run"]
