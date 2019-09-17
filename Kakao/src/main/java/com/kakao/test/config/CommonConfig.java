package com.kakao.test.config;

import lombok.ToString;
import org.apache.http.client.HttpClient;
import org.apache.http.impl.client.HttpClientBuilder;
import org.modelmapper.ModelMapper;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.client.HttpComponentsClientHttpRequestFactory;
import org.springframework.web.client.RestTemplate;

@Configuration
@ToString
public class CommonConfig {
    @Bean
    public RestTemplate restTemplate() {
        HttpComponentsClientHttpRequestFactory factory = new HttpComponentsClientHttpRequestFactory();
        HttpClient client = HttpClientBuilder.create()
                .setMaxConnTotal(50)
                .setMaxConnPerRoute(20)
                .build();
        factory.setHttpClient(client);
        factory.setConnectTimeout(2000);
        factory.setReadTimeout(5000);
        return new RestTemplate(factory);
    }

    @Bean
    public ModelMapper modelMapper() {
        return new ModelMapper();
    }

}
