#!/bin/sh
if [ $DEPLOYMENT_LOCATION = "YES" ]
then
cp -R lab5/Binaries/IOS/Payload/lab5.app/ $DSTROOT/$LOCAL_APPS_DIR/lab5.app
fi
