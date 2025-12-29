<?php
$data = [
    "lukman" => 'Jelek',
    "rani" => [
        "nilai_rani" => 90,
        "teman" => [
            "adam" => 'IT'
        ]
    ]
];

$nama = ["lukman", "rani"];
echo $data["lukman"]."\n";
foreach($data["rani"] as $d){
    if($d != 90){
        foreach($d as $key => $value){
            echo "Key :".$key.' Value : '.$value;
        }
    }else{
        echo $d."\n";
    }
}




?>
