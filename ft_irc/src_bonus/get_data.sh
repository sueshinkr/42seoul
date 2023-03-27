#! /bin/bash
# 서울 : %EC%84%9C%EC%9A%B8
URL="http://swopenapi.seoul.go.kr/api/subway/sample/xml/realtimeStationArrival/0/5/"$1
raw=$(curl --include --request GET $URL)
substr="</row>"
text=$raw
res=$2"="
err_sindex=${text%%"<code>"*}
err_sidx=$(echo $((${#err_sindex})))
err_eindex=${text%%"</code>"*}
erre_eidx=$(echo $((${#err_eindex})))
err_code=${text:$err_sidx+6:$erre_eidx-$err_sidx-6}
if [ ${err_code} != "INFO-000" ] ; then
    res+="Error"
    echo $res
    exit 1
fi
while :
do
    index=${text%%$substr*}
    idx=$(echo $((${#index})))
    len=$(echo "${#text}")
    if [ ${len} -eq ${idx} ] ; then
        break
    fi
    row=${text:0:$idx}
    trainLine_sindex=${row%%"<trainLineNm>"*}
    trainLine_sidx=$(echo $((${#trainLine_sindex})))
    trainLine_eindex=${row%%"</trainLineNm>"*}
    trainLine_eidx=$(echo $((${#trainLine_eindex})))
    trainLine=${row:$trainLine_sidx+13:$trainLine_eidx-$trainLine_sidx-13}

    arvmsg_sindex=${row%%"<arvlMsg2>"*}
    arvmsg_sidx=$(echo $((${#arvmsg_sindex})))
    arvmsg_eindex=${row%%"</arvlMsg2>"*}
    arvmsg_eidx=$(echo $((${#arvmsg_eindex})))
    arvmsg=${row:$arvmsg_sidx+10:$arvmsg_eidx-$arvmsg_sidx-10}

    arvmsg2_sindex=${row%%"<arvlMsg3>"*}
    arvmsg2_sidx=$(echo $((${#arvmsg2_sindex})))
    arvmsg2_eindex=${row%%"</arvlMsg3>"*}
    arvmsg2_eidx=$(echo $((${#arvmsg2_eindex})))
    arvmsg2=${row:$arvmsg2_sidx+10:$arvmsg2_eidx-$arvmsg2_sidx-10}

    subwayId_sindex=${row%%"<subwayId>"*}
    subwayId_sidx=$(echo $((${#subwayId_sindex})))
    subwayId_eindex=${row%%"</subwayId>"*}
    subwayId_eidx=$(echo $((${#subwayId_eindex})))
    subwayId=${row:$subwayId_sidx+10:$subwayId_eidx-$subwayId_sidx-10}

    exTime_sindex=${row%%"<barvlDt>"*}
    exTime_sidx=$(echo $((${#exTime_sindex})))
    exTime_eindex=${row%%"</barvlDt>"*}
    exTime_eidx=$(echo $((${#exTime_eindex})))
    exTime=${row:$exTime_sidx+9:$exTime_eidx-$exTime_sidx-9}
 
    text=${text:$idx+5}
    res+=$subwayId
    res+="@"
    res+=$trainLine
    res+="@"
    res+=$arvmsg
    res+="@"
    res+=$arvmsg2
    res+="@"
    res+=$exTime
    res+="#"
done
echo $res