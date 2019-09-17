package com.kakao.test.config;

import lombok.ToString;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
@ToString
public class ApiInfo {
    @Value("${url.base}")
    public String base;

    @Value("${url.actions}")
    public String actions;

    @Value("${url.oncalls}")
    public String oncalls;

    @Value("${url.start}")
    public String start;

    @Value("${user_key}")
    public String userKey;

    public String problemId;
    public String numberOfElevators;
    public String authCode;
}
